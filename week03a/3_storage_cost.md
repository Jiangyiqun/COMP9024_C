# cost

## assumption

- pointer: 4b
- vertex: 4b
- linked-list node 8b
- adjacency matrix element 1b(boolean value)

## adjacency matrix

always require V*4(pointer) + V * (V*1)

## adjacency list

V*4(pointer) + 2E * 8

## compare

matrix - list = V^2 - 16E

for V^2 > 16E, then martix > list