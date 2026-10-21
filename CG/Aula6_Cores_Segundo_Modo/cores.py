import colorsys
from PIL import Image

def createHSVImage(widgth, heigth, grausH, pctS, pctV, fileName):

    h = grausH / 360
    s = pctS / 100
    v = pctV / 100

    r, g, b = colorsys.hsv_to_rgb(h, s, v)

    rInt = int(r * 255)
    gInt = int(g * 255)
    bInt = int(b * 255)

    image = Image.new("RGB", (widgth, heigth), (rInt, gInt, bInt))
    image.save(fileName)
    
# from PIL import Image

# def createAlphaComposition():

#     width, height = 400, 400
#     backGround = Image.new("RGBA", (width, height), (255, 0, 0, 255))
#     backGround.save("alphaBackground.png")


#     firstPlan = Image.new("RGBA", (width, height), (0, 0, 255, 127))
#     firstPlan.save("firstAlphaPlan.png")

#     result = Image.alpha_composite(backGround, firstPlan)
#     result.save("AlphaResult.png")



# if __name__ == "__main__":
#     createAlphaComposition()