from PIL import Image

#folder of image
path="C:/E4YUGIRI/Yugiri_Simulator/images/config/"
#name of image
img_name="back.jpg"
#透明 paramater
alpha=128
img=Image.open(path+img_name)
print(img)
img.putalpha(alpha)
print(img)
img.show()

img.save(path+"back_alpha.png")#jpgだとエラー