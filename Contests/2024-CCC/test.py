import sys

keys_pressed = [x for x in str(sys.stdin.readline().strip())]
letters_displayed = set(str(sys.stdin.readline().strip()))

seen_keys = set()
silly_key = ""

for key in keys_pressed:
    if key in letters_displayed:
        seen_keys.add(key)
    elif key not in seen_keys:
        silly_key = f"{key} {letters_displayed.pop()}"
        break

quiet_key = "-" if len(seen_keys) == len(
    letters_displayed) else list(seen_keys)[0]

print(silly_key)
print(quiet_key)
