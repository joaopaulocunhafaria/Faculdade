def format_to_mif(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    mif_content = ""
    for line in lines:
        line = line.strip()
        if not line:
            line = "000000000000000000000000000000000000"
        mif_content += line + "\n"

    with open(output_file, 'w') as file:
        file.write(mif_content)

# Exemplo de uso
format_to_mif('pytthontxttomif/input.txt', 'pytthontxttomif/output.mif')