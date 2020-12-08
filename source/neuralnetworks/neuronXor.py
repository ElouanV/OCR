import numpy as np

nb_input = 2  #nombre d'inputs
nb_output = 1  #nombre de de neurone de sortie
nb_hidden = 2 #nombre de neurones sur le layer cachée

weights_hidden = np.array([[0.6, 1], [0.6, 1]])  #matrice representant poids neurones intermediaires
bias_hidden = np.array([[-1, -1]]) #matrice representant les biais des neurones intermediares

weights_output = np.array([[-1], [1]]) #matrice reprensentant les poids sortie
bias_output = np.array([[-1]]) # matrice representant le biais du neurone de sortie

input1 = np.array([[1, 1]]) # un des exemples sur les quatres possibles
input2 = np.array([[1, 0]])
input3 = np.array([[0, 1]])
input4 = np.array([[0, 0]])


def activate(z): #fonction "relu" d'activation
    for i in range(len(z)):
        for j in range(len(z[i])):
            if z[i][j] < 0:
                z[i][j] = 0
            else:
                z[i][j] = 1


res_hidden_input1 = np.dot(input1, weights_hidden) + bias_hidden
activate(res_hidden_input1) #resultat au hidden layer
resInput1 = np.dot(res_hidden_input1, weights_output) + bias_output
activate(resInput1)# resultat final

res_hidden_input2 = np.dot(input2, weights_hidden) + bias_hidden
activate(res_hidden_input2) #resultat au hidden layer
resInput2 = np.dot(res_hidden_input2, weights_output) + bias_output
activate(resInput2)# resultat final

res_hidden_input3 = np.dot(input3, weights_hidden) + bias_hidden
activate(res_hidden_input3) #resultat au hidden layer
resInput3 = np.dot(res_hidden_input3, weights_output) + bias_output
activate(resInput3)# resultat final

res_hidden_input4 = np.dot(input4, weights_hidden) + bias_hidden
activate(res_hidden_input4)  #resultat au hidden layer
resInput4 = np.dot(res_hidden_input4, weights_output) + bias_output
activate(resInput4) #resultat final

#affichage du resultat en fonction de l'input
print("Input: ", str(input1), " result = ", str(resInput1))
print("Input: ", str(input2), " result = ", str(resInput2))
print("Input: ", str(input3), " result = ", str(resInput3))
print("Input: ", str(input4), " result = ", str(resInput4))



