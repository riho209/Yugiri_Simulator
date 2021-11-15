from PIL import Image

#folder of image
path="C:/E4YUGIRI/Yugiri_Simulator/images/config/"
#name of image
img_name="rank.png"
#resize paramater
new_w=400
new_h=300
img=Image.open(path+img_name)
print(img)
img=img.resize((new_w,new_h))
print(img)
img.show()

img.save(path+img_name)