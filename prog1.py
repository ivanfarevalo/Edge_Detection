import argparse
import math
import os

import cv2
import numpy as np
import scipy.misc
import scipy.signal
from matplotlib import pyplot as plt


def create_gaussian_kernel(sigma_size):
    """
    Creates a gaussian kernel based on sigma and dimensions of kernel matrix
    :param sigma_size: standard deviation of gaussian
    :param kernel_dimensions: kernel dimensions
    """
    # Can modify kernel_dimension ration to sigma_size
    kernel_dimensions = 6 * sigma_size + 1
    gaussian_coefficient = 1/(2*math.pi*(sigma_size**2))
    gaussian_sum = 0
    gaussian_kernel = np.array([[0.0 for l in range(kernel_dimensions)] for w in range(kernel_dimensions)])

    for x in range(0, kernel_dimensions):
        for y in range(0, kernel_dimensions):
            i = x - math.floor(kernel_dimensions / 2)
            j = y - math.floor(kernel_dimensions / 2)
            gaussian_exponential = math.exp(-((i**2)+(j**2))/(2*sigma_size**2))
            # print("iteration {}:{}--> i: {} j: {}   var = {}".format(x, y, i, j, gaussian_exponential))
            gaussian_kernel[x, y] = gaussian_coefficient*gaussian_exponential
            gaussian_sum += gaussian_kernel[x, y]

    normalized_gaussian_kernel = (1/gaussian_sum)*gaussian_kernel
    return normalized_gaussian_kernel


def create_laplacian_of_gaussian_kernel(gaussian_kernel):
    laplacian_operator_matrix = np.array([[0, -1, 0], [-1, 4, -1], [0, -1, 0]])
    laplacian_of_gaussian_kernel = scipy.signal.fftconvolve(gaussian_kernel, laplacian_operator_matrix, mode='full')
    return laplacian_of_gaussian_kernel


def apply_laplacian_of_gaussian_to_image(image, laplacian_of_gaussian):
    output_picture_edges = cv2.filter2D(image, cv2.CV_32F, laplacian_of_gaussian)
    return output_picture_edges


def create_edge_picture_form_zero_crossing_locations(edge_image):
    edge_image_size = int(edge_image.shape[0])
    processed_edge_image = np.zeros((edge_image_size, edge_image_size), np.bool_)
    for x in range(edge_image_size-1):
        for y in range(edge_image_size-1):
            a = edge_image[x, y] * edge_image[x + 1, y]
            b = edge_image[x, y] * edge_image[x, y + 1]
            if a < 0 or b < 0:
                processed_edge_image[x, y] = 1
    return processed_edge_image


def blur_image(gaussian_kernel, image):
    return cv2.filter2D(image, -1, gaussian_kernel)


def input_image_to_edge_map(sigma, image):
    gaussian_kernel = create_gaussian_kernel(sigma)
    laplacian_of_gaussian = create_laplacian_of_gaussian_kernel(gaussian_kernel)
    output_picture_edges = apply_laplacian_of_gaussian_to_image(image, laplacian_of_gaussian)
    output_picture_zero_crossing_edges = create_edge_picture_form_zero_crossing_locations(output_picture_edges)

    return output_picture_zero_crossing_edges


def save_edge_maps(input_file_path, file_number, edge_map):
    input_file_name = os.path.split(input_file_path)[1][:-4]
    output_file_name = "{}_{}.png".format(input_file_name, file_number)
    print(output_file_name)

    plt.imsave(output_file_name, edge_map, cmap='gray')


def main():
    # Load a color image in grayscale

    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--image", required=True,
                    help="path to the input image")
    args = vars(ap.parse_args())
    print(args['image'])
    input_image_name = (args['image'])
    im = cv2.imread(input_image_name, 0)

    output_picture_zero_crossing_edges0 = input_image_to_edge_map(3, im)
    save_edge_maps(input_image_name, 0, output_picture_zero_crossing_edges0)

    output_picture_zero_crossing_edges1 = input_image_to_edge_map(6, im)
    save_edge_maps(input_image_name, 1, output_picture_zero_crossing_edges1)

    output_picture_zero_crossing_edges2 = input_image_to_edge_map(12, im)
    save_edge_maps(input_image_name, 2, output_picture_zero_crossing_edges2)

    output_picture_zero_crossing_edges3 = input_image_to_edge_map(24, im)
    save_edge_maps(input_image_name, 3, output_picture_zero_crossing_edges3)

    output_picture_zero_crossing_edges4 = input_image_to_edge_map(48, im)
    save_edge_maps(input_image_name, 4, output_picture_zero_crossing_edges4)

    plt.subplot(231), plt.imshow(output_picture_zero_crossing_edges0,cmap = 'gray'), plt.title('Edges')
    plt.xticks([]), plt.yticks([])
    plt.subplot(232), plt.imshow(output_picture_zero_crossing_edges1, cmap='gray'), plt.title('Edges')
    plt.xticks([]), plt.yticks([])
    plt.subplot(233), plt.imshow(output_picture_zero_crossing_edges2, cmap='gray'), plt.title('Edges')
    plt.xticks([]), plt.yticks([])
    plt.subplot(234), plt.imshow(output_picture_zero_crossing_edges3, cmap='gray'), plt.title('Edges')
    plt.xticks([]), plt.yticks([])
    plt.subplot(235), plt.imshow(output_picture_zero_crossing_edges4, cmap='gray'), plt.title('Edges')
    plt.xticks([]), plt.yticks([])
    plt.show()


if __name__ == '__main__':
    main()
