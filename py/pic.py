from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")

after = before.filter(ImageFilter.FIND_EDGES)
after.save("out2.bmp")


