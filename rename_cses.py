from pathlib import Path

QUESTION_CODE = "E"

FOLDER_INPUT_PATH = Path(__file__).parent / f"{QUESTION_CODE}/input"
FOLDER_OUTPUT_PATH = Path(__file__).parent / f"{QUESTION_CODE}/output"

def rename_prefix(folder_path: Path)->None:
    for file_path in folder_path.iterdir():
        if file_path.is_file():
            file_stem = file_path.stem
            new_name = f"{QUESTION_CODE}_{file_stem}"  # no extension
            new_path = file_path.parent / new_name
            counter = 1
            while new_path.exists():
                new_path = file_path.parent / f"{new_name}_{counter}"
                counter += 1
            file_path.rename(new_path)
            print(f"Renamed: {file_path.name} -> {new_path.name}")


rename_prefix(FOLDER_INPUT_PATH)
rename_prefix(FOLDER_OUTPUT_PATH)