from PIL import Image
import os

def create_pdf():
    base_dir = r"C:\Users\Admin\Desktop\DE HSG BINH DINH\DE BAI"
    output_path = r"C:\Users\Admin\Desktop\DE HSG BINH DINH\DE_THI_FULL.pdf"
    
    # Files in order
    files = [
        "503560434_4112351325754290_6960778127420444673_n.jpg", # Page 1
        "503500246_4112351512420938_3115323847179186057_n.jpg", # Page 2
        "503503441_4112351232420966_8827362564775042608_n.jpg", # Page 3
        "503555393_4112351395754283_1641347120827174044_n.jpg"  # Page 4
    ]
    
    image_list = []
    
    # Load first image
    first_path = os.path.join(base_dir, files[0])
    if not os.path.exists(first_path):
        print(f"Error: {first_path} not found")
        return

    first_image = Image.open(first_path)
    if first_image.mode != "RGB":
        first_image = first_image.convert("RGB")
        
    # Load remaining images
    for f in files[1:]:
        fpath = os.path.join(base_dir, f)
        if os.path.exists(fpath):
            img = Image.open(fpath)
            if img.mode != "RGB":
                img = img.convert("RGB")
            image_list.append(img)
            
    # Save PDF
    first_image.save(output_path, "PDF", resolution=100.0, save_all=True, append_images=image_list)
    print(f"PDF created at: {output_path}")

if __name__ == "__main__":
    create_pdf()
