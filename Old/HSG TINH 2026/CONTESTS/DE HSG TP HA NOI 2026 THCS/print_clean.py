
try:
    with open('de_bai_full.txt', 'r', encoding='utf-16le') as f:
        content = f.read()
    print(content)
except Exception as e:
    print(f"Error: {e}")
    # Try utf-8
    try:
        with open('de_bai_full.txt', 'r', encoding='utf-8') as f:
            content = f.read()
        print(content)
    except:
        pass
