import cv2
import numpy as np
import numpy
import random
from matplotlib import pyplot as plt
from PIL import Image


def binarize_image(img_path, target_path,threshold):
    image_file = Image.open(img_path)
    image = image_file.convert('L')
    image = numpy.array(image)
    image = binarize_array(image,threshold)
    cv2.imwrite(target_path,image)

def binarize_array(numpy_array, threshold = 200):
    for i in range(len(numpy_array)):
        for j in range(len(numpy_array[0])):
            if numpy_array[i][j]>threshold:
                numpy_array[i][j] = 0
            else:
                numpy_array[i][j] = 255
    return numpy_array

binarize_image('TEST.jpg','BW.jpg',200)

bw = cv2.imread('BW.jpg')
height,width,channels = bw.shape

print(height,width)

def rowpixelist(image):
    pixel = image
    ligne = 0
    white = 0
    heigh = len(bw)
    widt = len(bw[0])
    count = 0
    whitelist = []
    for row in range(heigh):
        whitelist.append((count,white))
        white = 0
        count += 1
        for column in range(widt):
            if np.any(pixel[row][column] == 255):
                white += 1
    return whitelist


def rowcounter(liste):
    L =[]
    start = 0
    row = 0
    rowcounter = 0
    i = 0
    length = len(liste) - 1
    while i <= length -1:
        row += 1
        if (rowcounter != 0):
            L.append((start, rowcounter))
        rowcounter = 0
        (z,y) = liste[i]
        (a,b) = liste[i+1]
        if (y == 0 and b != 0) or (y != 0 and b == 0):
            i+=1
            start = row
            (z, y) = liste[i]
            (a, b) = liste[i + 1]
            while(y!=0 and b != 0 and i <= length-1):
                row+=1
                (z, y) = liste[i]
                (a, b) = liste[i + 1]
                rowcounter +=1
                i+=1
        else:
            i+=1
    return L

print(rowcounter(rowpixelist(bw)))



def columnpixelist(image,uperow,intermediaterow):
    pixel = image
    heigh = len(image)
    widt = len(image[0])
    whiteliste2 = []
    white2 = 0
    count2 = 0
    for column in range(widt):
        whiteliste2.append((count2, white2))
        white2 = 0
        count2 += 1
        for row in range(uperow,uperow+intermediaterow+1):
            if np.any(pixel[row][column] == 255):
                white2 += 1
    return whiteliste2




def verticalign(image,columnlist,uperow,intermediaterow):
    x = 0
    length = len(columnlist) - 1
    while x <= length -2:
        (z, y) = columnlist[x]
        (a, b) = columnlist[x + 1]
        (k, n) = columnlist[x + 2]
        if (y == 0 and b == 0 and n != 0):
            cv2.line(image, (a, uperow), (a, uperow+intermediaterow), (0, 0, 255), 1)
            x += 1
        else:
            x += 1
    return image



def horizontalign(image,rowlist):
    i = 0
    length = len(rowlist) - 1
    while i <= length -1:
        (z,y) = rowlist[i]
        (a,b) = rowlist[i+1]
        if (y == 0 and b != 0) or (y != 0 and b == 0):
            cv2.line(image,(0,a),(width,a),(0,0,255),1)
            i+=1
        else:
            i+=1
    return image



def assemble(image):
    rowlist = rowpixelist(image)
    lists = rowcounter(rowlist)
    length = len(lists) -1
    i = 0
    while i <= length:
        (a,b) = lists[i]
        columnlist = columnpixelist(image,a,b)
        image = verticalign(image, columnlist, a, b)
        i+=1
    image = horizontalign(image,rowlist)
    return image



bw2 = assemble(bw)
cv2.imshow("FINAL",bw2)
cv2.waitKey(0)
cv2.destroyAllWindows()

















