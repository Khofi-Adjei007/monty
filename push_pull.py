stack = []  # Stack to save the elements

def push(l_number, args):
    try:
        value = int(args)
        stack.append(value)
    except ValueError:
        print(f"L{li_number}: usage: push integer")
        exit(1)

def pall():
    for value in reversed(stack):
        print(value)
