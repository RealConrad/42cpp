import sys

def is_sorted_ascending(input_str):
    numbers_str = input_str.split()
    numbers = [int(num) for num in numbers_str]
    
    for i in range(len(numbers) - 1):
        if numbers[i] > numbers[i + 1]:
            return False
    return True

if __name__ == "__main__":
    # Check if at least one argument is provided
    if len(sys.argv) > 1:
        input_str = sys.argv[1]
        result = is_sorted_ascending(input_str)
        print(result)  # Prints True if sorted, False otherwise.
    else:
        print("Please provide a string of numbers as an argument.")

#USGAE:
# $>python check_sorted.py "numbers separated by space"