import cv2
import numpy as np
import numpy
import random
from matplotlib import pyplot as plt
from PIL import Image

#Pour utiliser la fonction crop, une explication se trouve sous la fonction cropping.

def binarize_image(img_path, target_path,threshold):    #Binarisation de l'image
    image_file = Image.open(img_path)
    image = image_file.convert('L')
    image = numpy.array(image)
    image = binarize_array(image,threshold)
    cv2.imwrite(target_path,image)

def binarize_array(numpy_array, threshold = 200):       #Binarisation de la matrice
    for i in range(len(numpy_array)):
        for j in range(len(numpy_array[0])):
            if numpy_array[i][j]>threshold:
                numpy_array[i][j] = 0
            else:
                numpy_array[i][j] = 255
    return numpy_array

binarize_image('nom_fichier','BW.jpg',100)             #Rentrer le nom de votre fichier à l'emplacement prévus pour cela
bw = cv2.imread('BW.jpg')
height,width,channels = bw.shape

def rowpixelist(image):                                #fonction permettant de compter le nombre de pixel blanc par ligne dans la matrice
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


def rowcounter(liste):                              #fonction permettant de calculer le début et la fin d'une ligne de texte
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

def columnpixelist(image,uperow,intermediaterow):              #fonction calculant le nombre de pixel blanc par colonne
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

def columncounter(liste):                                      #fonction calculer de trouver le début et la fin d'une lettre
    L = []
    start = 0
    column = 0
    columncounter = 0
    i = 0
    length = len(liste) - 1
    while i <= length - 2:
        column += 1
        if (columncounter != 0):
            L.append((start, columncounter+3))
        columncounter = 0
        (z, y) = liste[i]
        (a, b) = liste[i + 1]
        (k, n) = liste[i + 2]
        if (y == 0 and b == 0 and n != 0):
            i += 3
            start = column
            (z, y) = liste[i]
            (a, b) = liste[i + 1]
            (k, n) = liste[i + 2]
            while (n != 0 and  i <= length - 2):
                column += 1
                (z, y) = liste[i]
                (a, b) = liste[i + 1]
                (k, n) = liste[i + 2]
                columncounter += 1
                i += 1
        else:
            i += 1
    return L

print(columncounter(columnpixelist(bw,10,13)))




def verticalign(image,columnlist,uperow,intermediaterow):                       #fonction tracant des lignes verticales rouges pour délimiter les charactères
    x = 0
    length = len(columnlist) - 1
    while x <= length -2:
        (z, y) = columnlist[x]
        (a, b) = columnlist[x + 1]
        (k, n) = columnlist[x + 2]
        if (y == 0 and b == 0 and n != 0):
            cv2.line(image, (z, uperow), (z, uperow+intermediaterow), (0, 0, 255), 1)
            x += 1
        else:
            x += 1
    return image

def horizontalign(image,rowlist):                                   #fonction tracant des lignes horizontales rouges pour délimiter les lignes
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




def assemble(image):                                            #fonction qui permet de faire apparaître la segmentation en entier sur l'image
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


def crop(image, rowlist, columnlist):  # fonction qui va découper l'image en plusieur charactères et va les sauvegarder dans le dossier. Attention, cette fonction ne marche qu'avec des images contenant une ligne de text
    x = 0
    length1 = len(rowlist) - 1
    (x1,y1) = rowlist
    length = len(columnlist) - 1
    img = Image.open(image)
    i = 0
    while i <= length:
        (a, b) = columnlist[i]
        column = a + b
        x += 1
        cropped = img.crop((a, x1, column, x1 + y1))
        cropped.save("character" + str(x) + ".png")
        i += 1


#crop('final.jpg',(9, 13),[(60, 7), (69, 7), (78, 5), (92, 7), (108, 5), (125, 7), (139, 7), (171, 5), (180, 7), (194, 5), (205, 6), (213, 6), (220, 5), (238, 5), (245, 6)])
#exemple d'utilisation avec l'image TEST.PNG

bw2 = assemble(bw)
cv2.imshow("FINAL",bw2)
cv2.imwrite("final.jpg",bw2)
cv2.waitKey(0)
cv2.destroyAllWindows()


















