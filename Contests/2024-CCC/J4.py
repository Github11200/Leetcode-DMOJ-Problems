import sys

keys_pressed = [x for x in str(sys.stdin.readline().strip())]
letters_displayed = [x for x in str(sys.stdin.readline().strip())]

i = 0
j = 0

quite_key = "-"
silly_key = "/"

goofy_key_pressed = False

while i < len(keys_pressed):
    new_index = -1
    if j >= len(letters_displayed):
        quite_key = keys_pressed[i]
    elif keys_pressed[i] == letters_displayed[j] or keys_pressed[i] == silly_key[0] or goofy_key_pressed:
        if goofy_key_pressed:
            goofy_key_pressed = False
        i += 1
        j += 1
        continue
    else:
        quite_key_found = False
        for k in range(i, len(keys_pressed)):
            if keys_pressed[k] == letters_displayed[j]:
                quite_key = keys_pressed[i]
                for l in range(i, k):
                    letters_displayed.insert(l, keys_pressed[i])
                quite_key_found = True
                new_index = k
                break
        if not quite_key_found:
            silly_key = f"{keys_pressed[i]} {letters_displayed[j]}"
        goofy_key_pressed = True
    if new_index == -1:
        i += 1
        j += 1
    else:
        i = new_index
        j = new_index

print(silly_key)
print(quite_key)
