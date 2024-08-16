def format_array(array):
    # Calcula a largura máxima de cada coluna, incluindo uma margem extra para espaçamento
    col_widths = [max(len(str(item)) for item in col) for col in zip(*array)]

    # Formata cada linha do array
    formatted_rows = []
    for row in array:
        formatted_row = ',  '.join(f"{str(item).ljust(width)}" for item, width in zip(row, col_widths))
        formatted_rows.append(f"{formatted_row} ,")

    # Retorna o resultado formatado como uma string
    return '\n'.join(formatted_rows)

# Exemplo de uso:
array = [
    ["TD(TD_ESC_CAPS)", "KC_Q", "KC_W", "KC_E", "KC_R", "KC_T", "KC_Y", "KC_U", "KC_I", "KC_O", "KC_P", "KC_BSPC"],
    ["KC_TAB", "KC_A", "KC_S", "KC_D", "KC_F", "KC_G", "KC_H", "KC_J", "KC_K", "KC_L", "BR_CCED", "BR_TILD"],
    ["KC_LSFT", "KC_Z", "KC_X", "KC_C", "KC_V", "KC_B", "KC_N", "KC_M", "KC_COMM", "KC_DOT", "KC_LBRC", "KC_RBRC"],
    ["KC_LCTL", "BR_BSLS", "KC_LALT", "KC_LGUI", "LOWER", "KC_SPC", "KC_ENT", "RAISE", "KC_SLSH", "KC_RALT", "KC_MINUS", "KC_EQUAL"]
]

formatted_string = format_array(array)
print(formatted_string)
