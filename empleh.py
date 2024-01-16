from string import ascii_lowercase

board='''+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|...|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
'''

row = 0
col = 0
d = {}
for i in range(1, len(board) - 1):
    if board[i] in '.:' and board[i] == board[i - 1] and board[i] == board[i + 1]:
        d[(8 - row, ascii_lowercase[col])] = i
        col += 1
        row += col//8
        col %= 8

changes = {}

white = input().replace("White: ",'').strip().split(',')
black = input().replace("Black: ",'').strip().split(',')

for pos in white:
    if len(pos) == 0: continue
    if len(pos) < 3: pos = 'P' + pos
    changes[d[(int(pos[2]), pos[1])]] = pos[0]

for pos in black:
    if len(pos) == 0: continue
    if len(pos) < 3: pos = 'P' + pos
    changes[d[(int(pos[2]), pos[1])]] = pos[0].lower()

for i in range(len(board)):
    if i in changes:
        print(changes[i], end='')
    else:
        print(board[i], end='')
print()
