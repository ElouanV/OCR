# coding=utf-8
import numpy as np

# Valeurs issues du reseau de neurone (1 input_layer de 2 neurones , 1 hidden layer de 2 neurones et 1 output layer
# de 1 neurone)
nb_input = 2
nb_hidden = 2
nb_output = 1

# Creation de matrices poids et bias pour le hidden layer et le output layer avec des valeurs aléatoires issues de la
# loi Gaussienne
weights_hidden = np.random.randn(2, 2)
bias_hidden = np.random.randn(1, 2)

weights_output = np.random.randn(2, 1)
bias_output = np.random.randn(1, 1)

# Valeurs de Tests pour entrainer le réseau
input_test = np.array([[1, 1],
                       [0, 1],
                       [0, 0]])

input_result = np.array([[0],
                         [1],
                         [0]])


#Fonction d'activation sigmoid
def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))


def sigmoid_prime(z):
    return sigmoid(z) * (1 - sigmoid(z))


# Entrainement a 10000 iterations
nb_training_iteration = 10000

for i in range(nb_training_iteration):
    # On applique la formule d'activation (sigmoid) a nos 2 layers (hidden et output)
    hidden_layer = np.dot(input_test, weights_hidden) + bias_hidden
    sigmoid(hidden_layer)
    output_layer = np.dot(hidden_layer, weights_output) + bias_output
    sigmoid(output_layer)

    #Backpropagation
    # On calcule le cout du reseau sur les exemples servant a l'apprentissage
    cost = (output_layer - input_result) ** 2
    z = np.dot(hidden_layer, weights_output) + bias_output

    # On calcule la difference delta issu du résultat de la descente de gradient et on l'applique sur les bias
    # et les poids établis au préalable
    weight_output_delta = np.dot(hidden_layer.T, sigmoid_prime(z)) * (2 * (
        np.sum(input_result - output_layer)))
    bias_output_delta = np.dot(sigmoid_prime(z).T, (2 * (output_layer - input_result)))

    weights_output += weight_output_delta
    bias_output += bias_output_delta

    z = np.dot(input_test, weights_hidden) + bias_hidden
    j = 0
    z2 = np.array([[0, 0]])
    for j in range(len(z)):
        z2[0][0] += z[j][0]
        z2[0][1] += z[j][1]
    z2 = 0.25 * z2
    weights_hidden_delta = np.dot(input_test.T, sigmoid_prime(z)) * (2 * (np.sum(input_result -input_result)))
    bias_hidden_delta = sigmoid_prime(z2)

    weights_hidden += weights_hidden_delta
    bias_hidden += bias_hidden_delta

# Valeurs de tests une fois que le neurone est entrainé
inputs_test = np.array([[0, 1]])
# feedforward final qui test avec les valeurs non testées par le reseau durant la phase d'apprentissage
input_layer = inputs_test
hidden_layer = sigmoid(np.dot(input_layer, weights_hidden))
output_layer = sigmoid(np.dot(hidden_layer, weights_output))

# Affiche le resultat
if int(output_layer) > 0.5:
    print(1)
else:
    print(0)
