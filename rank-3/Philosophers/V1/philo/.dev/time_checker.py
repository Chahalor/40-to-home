import re
import argparse

ANSI_ESCAPE = re.compile(r'\x1b\[[0-9;]*m')

def parse_log_file(filepath):
	with open(filepath, 'r') as file:
		raw_lines = file.readlines()

	timestamps = []

	for idx, raw_line in enumerate(raw_lines):
		# Enlever les séquences ANSI
		line = ANSI_ESCAPE.sub('', raw_line).strip()

		# Séparer timestamp et message
		parts = line.split('|')
		if len(parts) < 2:
			continue

		try:
			timestamp = float(parts[0].strip())
			timestamps.append((idx, timestamp, line))
		except ValueError:
			continue

	# Analyse des différences de timestamps
	for i in range(len(timestamps)):
		start = max(0, i - 10)
		end = min(len(timestamps), i + 11)
		window = timestamps[start:end]

		for j in range(1, len(window)):
			diff = abs(window[j][1] - window[j - 1][1])
			if diff > 0.5:
				print(f"\n⚠️  Écart détecté à la ligne {filepath}:{timestamps[i][0] + 1} :")
				print(f"  {timestamps[i][2]} <--> {window[j][2]}")
				print(f"  Délai de {diff:.3f}s entre lignes {filepath}:{window[j-1][0]+1} et {window[j][0]+1}")
				break

def main():
	parser = argparse.ArgumentParser(description="Analyse un fichier de log pour détecter les écarts de temps.")
	parser.add_argument('filepath', type=str, help='Chemin du fichier de log à analyser.')
	args = parser.parse_args()

	parse_log_file(args.filepath)

if __name__ == "__main__":
	main()
