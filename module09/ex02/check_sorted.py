import sys

def is_sorted_ascending(input_str):
    numbers_str = input_str.split()
    numbers = [int(num) for num in numbers_str]
    
    # Initialize variables to track the required information
    numbers_checked = len(numbers) - 1  # Since we check in pairs, it's len(numbers) - 1 checks
    is_sorted = True  # Assume the list is sorted initially
    duplicates_found = False  # Assume no duplicates initially
    
    # A set to keep track of unique numbers for duplicate detection
    unique_numbers = set()
    
    for i in range(len(numbers) - 1):
        # Check for duplicates
        if numbers[i] in unique_numbers:
            duplicates_found = True
        else:
            unique_numbers.add(numbers[i])
        
        # Check if the current number is greater than the next one
        if numbers[i] > numbers[i + 1]:
            is_sorted = False
            # No need to check further if unsorted
            break
            
    # Check the last number for duplicates (not covered in the loop)
    if numbers[-1] in unique_numbers:
        duplicates_found = True
    else:
        unique_numbers.add(numbers[-1])
    
    return {
        "numbers_checked": numbers_checked + 1,
        "is_sorted": is_sorted,
        "duplicates_found": duplicates_found
    }


if __name__ == "__main__":
    # Check if at least one argument is provided
    if len(sys.argv) > 1:
        input_str = sys.argv[1]
        result = is_sorted_ascending(input_str)
        print(result)  # Prints True if sorted, False otherwise.
    else:
        print("Please provide a string of numbers as an argument.")

#USGAE:
#NOTE: MUST BE IN STRING
# $>python check_sorted.py <"numbers separated by space">