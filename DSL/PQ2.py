from collections import Counter

def average_score(marks):
    if not marks:
        return 0
    return sum(marks) / len(marks)

def highest_and_lowest_score(marks):
    if not marks:
        return None, None
    return max(marks), min(marks)

def count_absent_students(marks):
    return marks.count(-1)

def most_frequent_mark(marks):
    if not marks:
        return None
    count = Counter(marks)
    most_common = count.most_common(1)
    return most_common[0][0] if most_common else None

def main():
    # Example data:
    # -1 indicates absent
    marks = [85, 90, 78, -1, 92, 85, 76, 90, -1, 88, 85]
    
    avg_score = average_score([mark for mark in marks if mark != -1])
    highest_score, lowest_score = highest_and_lowest_score([mark for mark in marks if mark != -1])
    absent_count = count_absent_students(marks)
    frequent_mark = most_frequent_mark([mark for mark in marks if mark != -1])

    print(f"Average score of the class: {avg_score:.2f}")
    print(f"Highest score of the class: {highest_score}")
    print(f"Lowest score of the class: {lowest_score}")
    print(f"Count of students who were absent: {absent_count}")
    print(f"Mark with highest frequency: {frequent_mark}")

if __name__ == "__main__":
    main()
