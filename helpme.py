from string import ascii_lowercase
from functools import cmp_to_key
def w_compare(a, b):
    s = "KQRBNP"
    ia = s.index(a[0])
    ib = s.index(b[0])
    if ia < ib: return -1
    elif ia > ib: return 1
    else:
        if int(a[2]) < int(b[2]):
            return -1
        elif int(a[2]) > int(b[2]):
            return 1
        else:
            return ascii_lowercase.index(a[1]) - ascii_lowercase.index(b[1])

def b_compare(a, b):
    s = "KQRBNP"
    ia = s.index(a[0])
    ib = s.index(b[0])
    if ia < ib:
        return -1
    elif ia > ib:
        return 1
    else:
        if int(a[2]) < int(b[2]):
            return 1
        elif int(a[2]) > int(b[2]):
            return -1
        else:
            return ascii_lowercase.index(a[1]) - ascii_lowercase.index(b[1])
row = 0
white = []
black = []
for i in range(17):
    l = input()
    if l[0] == '+': continue
    l = l.split('|')
    col = 0
    for j in l:
        if len(j) == 0:
            continue
        if j[1] not in '.:':
            if j[1].isupper():
                white.append(j[1] + ascii_lowercase[col] + str(8 - row))
            else:
                black.append(j[1].upper() + ascii_lowercase[col] + str(8 - row))
        col += 1
    row += 1
white = sorted(white, key=cmp_to_key(w_compare))
black = sorted(black, key=cmp_to_key(b_compare))
print("White: ", end='')

print((','.join(white)).replace('P',''))
print("Black: ", end='')
print((','.join(black)).replace('P',''))
