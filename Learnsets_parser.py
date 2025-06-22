import re


def parse_multiple_levelup_entries(c_code):
    # Pattern to match entire learnset blocks
    block_pattern = re.compile(
        r'static const struct LevelUpMove s(\w+)LevelUpLearnset\[\] = \{(.*?)LEVEL_UP_END\s*\};',
        re.DOTALL
    )

    # Pattern to match individual moves
    move_pattern = re.compile(r'LEVEL_UP_MOVE\(\s*(\d+),\s*MOVE_(\w+)\)')

    output = []

    for match in block_pattern.finditer(c_code):
        pokemon_name = match.group(1)
        block = match.group(2)
        output.append(f"{pokemon_name}:")

        for move_match in move_pattern.finditer(block):
            level = move_match.group(1)
            move = move_match.group(2).replace("_", " ").title()
            output.append(f"{level} - {move}")

        output.append("")  # Add blank line between Pokémon

    return "\n".join(output)


# Example usage
#with open("c/Users/jwgra/RomHacking/pokeemerald-expansion-hack/src/data/pokemon/level_up_learnsets/gen_9.h", "r") as file:
  #  c_file_contents = file.read()

with open("C://Users/jwgra/RomHacking/pokeemerald-expansion-hack/src/data/pokemon/level_up_learnsets/gen_9.h", "r") as file:
    c_file_contents = file.read()

parsed_output = parse_multiple_levelup_entries(c_file_contents)

# Print to console
# print(parsed_output)

# Optionally save to file
with open("Learnsets.txt", "w") as out_file:
    out_file.write(parsed_output)
