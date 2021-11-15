from PIL import Image,ImageDraw, ImageFilter

#folder of image
path="C:/E4YUGIRI/Yugiri_Simulator/images/config/"
#name of image
img_name="back.jpg"
#透明 paramater
alpha=128
img=Image.open(path+img_name)
im_rgb=img.copy()
im_a = Image.new("L", im_rgb.size, 0)
draw = ImageDraw.Draw(im_a)
draw.ellipse((140, 50, 260, 170), fill=255)

print(img)
img.putalpha(alpha)
print(img)
img.show()

img.save(path+"back_alpha.png")#jpgだとエラー