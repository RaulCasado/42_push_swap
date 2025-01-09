import random
import sys

def generate_unique_numbers(count, min_value, max_value):
    if count > (max_value - min_value + 1):
        raise ValueError("No es posible generar la cantidad solicitada de números únicos en el rango especificado.")

    unique_numbers = random.sample(range(min_value, max_value + 1), count)
    return unique_numbers

MIN_VALUE = -2**31
MAX_VALUE = 2**31 - 1

if __name__ == "__main__":
    try:
        if len(sys.argv) != 2:
            raise ValueError("Uso: python3 archivo.py <cantidad_de_numeros>")
        
        count = int(sys.argv[1])
        unique_numbers = generate_unique_numbers(count, MIN_VALUE, MAX_VALUE)

        print(" ".join(map(str, unique_numbers)))
    except ValueError as e:
        print(f"Error: {e}")
