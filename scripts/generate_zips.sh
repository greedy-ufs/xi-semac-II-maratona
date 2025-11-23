#!/bin/bash

# Script to generate zip files for each folder

# Get the script directory and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
QUESTIONS_DIR="$PROJECT_ROOT/questions"

echo "Generating zip files for folders in: $QUESTIONS_DIR"

# Change to questions directory to avoid full paths in zip
cd "$QUESTIONS_DIR" || exit 1

# Iterate through each single-letter directory (A-Z)
for dir in [A-Z]; do
    # Check if it's a directory
    if [ -d "$dir" ]; then
        zip_file="$PROJECT_ROOT/${dir}.zip"

        echo "Creating: $zip_file"
        (cd "$dir" && zip -r "$zip_file" .) > /dev/null 2>&1

        if [ $? -eq 0 ]; then
            echo "✓ Successfully created $zip_file"
        else
            echo "✗ Failed to create $zip_file"
        fi
    fi
done

echo "Done!"
