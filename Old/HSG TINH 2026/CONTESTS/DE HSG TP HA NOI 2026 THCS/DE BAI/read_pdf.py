import fitz

doc = fitz.open('DE BAI.pdf')
for i, page in enumerate(doc):
    if i == 0:
        print(f"\n=== TRANG {i+1} ===\n")
        print(page.get_text())
