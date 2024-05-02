import sys

def is_sorted_ascending(numbers):
    numbers_checked = len(numbers) - 1 
    is_sorted = True
    duplicates_found = False
    
    unique_numbers = set()
    for i in range(len(numbers) - 1):
        # Check for duplicates for each number in the loop
        if numbers[i] in unique_numbers:
            duplicates_found = True
        else:
            unique_numbers.add(numbers[i])

        # Check if the current number is greater than the next one
        if numbers[i] > numbers[i + 1]:
            is_sorted = False

    # The last number needs to be checked for duplicates as it's not covered in the loop
    if numbers[-1] in unique_numbers:
        duplicates_found = True
    else:
        unique_numbers.add(numbers[-1])
    
    return {
        "numbers_checked": len(numbers),
        "is_sorted": is_sorted,
        "duplicates_found": duplicates_found
    }


if __name__ == "__main__":
    if len(sys.argv) > 1:
        if len(sys.argv) == 2:
            # Input is a single string containing all numbers
            input_str = sys.argv[1]
            numbers = list(map(int, input_str.split()))
        else:
            # Input is multiple arguments
            numbers = list(map(int, sys.argv[1:]))

        result = is_sorted_ascending(numbers)
        print(result)
    else:
        print("Please provide numbers as arguments, either in a single string or as separate arguments.")