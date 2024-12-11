# Function to sort the array using Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to sort the array using Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Function to display the top five scores
def display_top_five(arr):
    top_five = arr[-1:-6:-1]  # Get the last five elements in descending order
    print("Top five scores:", top_five)

# Main function
def main():
    # Example array of student percentages
    percentages = [72.5, 85.4, 90.8, 88.7, 76.3, 91.2, 82.6, 95.5, 69.3, 88.9]
    print("Original percentages:", percentages)

    # Sorting using Insertion Sort
    insertion_sorted = percentages[:]
    insertion_sort(insertion_sorted)
    print("\nSorted percentages (Insertion Sort):", insertion_sorted)
    display_top_five(insertion_sorted)

    # Sorting using Shell Sort
    shell_sorted = percentages[:]
    shell_sort(shell_sorted)
    print("\nSorted percentages (Shell Sort):", shell_sorted)
    display_top_five(shell_sorted)

main()
