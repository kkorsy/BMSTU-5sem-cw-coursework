import numpy
from math import ceil, cos, sin, pi, sqrt
import matplotlib.pyplot as plt


poly_step = 0.25


def plot_grid(filename, ax):
    f = open(filename, 'r')

    lines = f.readlines()
    for i in range(0, len(lines), 3):
        l1, l2, l3 = list(map(float, lines[i].strip().split())), list(map(float, lines[i + 1].strip().split())), \
                     list(map(float, lines[i + 2].strip().split()))
        x, y, z = [l1[0], l2[0], l3[0], l1[0]], [l1[1], l2[1], l3[1], l1[1]], [l1[2], l2[2], l3[2], l1[2]]
        ax.plot(x, y, z)

    f.close()


def receptacle_func(x, y):
    return ((x - 1/4) ** 2) / 2 + (y ** 2) / 2 + 19


def get_receptacle(ax):
    # create grid
    f = open('receptacle_points.txt', 'w')

    x_start, x_stop, x_step = -2, 2.5, poly_step
    x_list = numpy.linspace(x_start, x_stop, ceil((x_stop - x_start) / x_step))
    y_start, y_stop, y_step = -2.25, 2.25, poly_step
    y_list = numpy.linspace(y_start, y_stop, ceil((y_stop - y_start) / y_step))

    coords_list = []

    for x in x_list:
        for y in y_list:
            z = receptacle_func(x, y)
            if z <= 21.55:
                f.write(str(x) + ';' + str(y) + ';' + str(z) + '\n')

                coords_list.append([x, y, z])

    f.close()

    x, y, z = numpy.array(list(i[0] for i in coords_list)), numpy.array(list(i[1] for i in coords_list)), numpy.array(list(i[2] for i in coords_list))
    ax.plot_trisurf(x, y, z, wflag=True, filename="receptacle_grid.txt")

    # plot grid
    # plot_grid('receptacle_grid.txt', ax)


def stem_func(t, z):
    return 0.6 * cos(t) + 1/5 * sin(z), 0.6 * sin(t)


def get_stem(ax):
    # create grid
    f = open('stem_points.txt', 'w')

    z_start, z_stop, z_step = 0, 20, 1
    z_list = numpy.linspace(z_start, z_stop, ceil((z_stop - z_start) / z_step))
    t_start, t_stop, t_step = 0, 2 * pi, pi/15
    t_list = numpy.linspace(t_start, t_stop, ceil((t_stop - t_start) / t_step))

    coords_list = []
    k = 0

    for z in z_list:
        coords_list.append([])
        for t in t_list:
            x, y = stem_func(t, z)
            f.write(str(x) + ';' + str(y) + ';' + str(z) + '\n')

            coords_list[k].append([x, y, z])
        k += 1

    f.close()

    f = open("stem_grid.txt", 'w')

    for i in range(len(coords_list) - 1):
        for j in range(len(coords_list[i]) - 1):
            f.write(str(coords_list[i][j][0]) + ' ' + str(coords_list[i][j][1]) + ' ' + str(coords_list[i][j][2]) + '\n')
            f.write(str(coords_list[i][j + 1][0]) + ' ' + str(coords_list[i][j + 1][1]) + ' ' + str(coords_list[i][j + 1][2]) + '\n')
            f.write(str(coords_list[i + 1][j + 1][0]) + ' ' + str(coords_list[i + 1][j + 1][1]) + ' ' + str(coords_list[i + 1][j + 1][2]) + '\n')

            f.write(str(coords_list[i][j][0]) + ' ' + str(coords_list[i][j][1]) + ' ' + str(coords_list[i][j][2]) + '\n')
            f.write(str(coords_list[i + 1][j][0]) + ' ' + str(coords_list[i + 1][j][1]) + ' ' + str(coords_list[i + 1][j][2]) + '\n')
            f.write(str(coords_list[i + 1][j + 1][0]) + ' ' + str(coords_list[i + 1][j + 1][1]) + ' ' + str(coords_list[i + 1][j + 1][2]) + '\n')

    f.close()

    # plot grid
    # plot_grid('stem_grid.txt', ax)


def petal_func(x, y):
    return 1/2 * (x ** 2) + y + 25


def get_petal(ax):
    f = open('petal_points.txt', 'w')

    x_start, x_stop, x_step = -5, 5, poly_step
    x_list = numpy.linspace(x_start, x_stop, ceil((x_stop - x_start) / x_step))
    y_start, y_stop, y_step = -5, 5, poly_step
    y_list = numpy.linspace(y_start, y_stop, ceil((y_stop - y_start) / y_step))

    coords_list = []

    for x in x_list:
        for y in y_list:
            if x ** 2 + 1/5 * (y ** 2) <= 3:
                z = petal_func(x, y)
                f.write(str(x) + ';' + str(y) + ';' + str(z) + '\n')

                coords_list.append([x, y, z])

    f.close()

    x, y, z = numpy.array(list(i[0] for i in coords_list)), numpy.array(list(i[1] for i in coords_list)), numpy.array(
        list(i[2] for i in coords_list))
    ax.plot_trisurf(x, y, z, wflag=True, filename="petal_grid.txt")

    # plot grid
    # plot_grid('petal_grid.txt', ax)


def leaf_func(t):
    if -3 * sqrt(3) <= t <= 0:
        return t * cos(-pi / 3) - 1/3 * (t ** 2) * sin(-pi / 3), t * sin(-pi / 3) + 1/3 * (t ** 2) * cos(-pi / 3), \
               -2 / (t - 1) - 3 * t
    return t, 1/3 * (t ** 2), 2 / (t + 1) + 3 * t


def vect_len(v):
    len_v = 0
    for i in v:
        len_v += i ** 2
    return sqrt(len_v)


def fill_matrix(phi, vx, vy, vz):
    return numpy.array(
        [[cos(phi) + (1 - cos(phi)) * (vx ** 2), (1 - cos(phi)) * vx * vy - sin(phi) * vz, (1 - cos(phi)) * vx * vz + sin(phi) * vy],
        [(1 - cos(phi)) * vy * vx + sin(phi) * vz, cos(phi) + (1 - cos(phi)) * (vy ** 2), (1 - cos(phi)) * vy * vz - sin(phi) * vx],
        [(1 - cos(phi)) * vz * vx - sin(phi) * vy, (1 - cos(phi)) * vz * vy + sin(phi) * vx, cos(phi) + (1 - cos(phi)) * (vz ** 2)]]
    )


def leaf_middle(x, y, z):
    v = [-3 * sqrt(3), -9, (27 - 120 * sqrt(3)) / 13]
    len_v = vect_len(v)
    v = list(i / len_v for i in v)

    matrix = fill_matrix(-pi / 10, v[0], v[1], v[2])
    coords = numpy.array([[x], [y], [z]])

    turned_coords = numpy.dot(matrix, coords)
    turned_coords = numpy.reshape(turned_coords, 3)
    return turned_coords[0], turned_coords[1], turned_coords[2]


def get_leaf(ax):
    # create grid
    f = open('leaf_points.txt', 'w')

    t_start, t_stop, t_step = -3 * sqrt(3), 3 * sqrt(3), poly_step
    t_list = numpy.linspace(t_start, t_stop, ceil((t_stop - t_start) / t_step))

    coords_list = []

    for t in t_list:
        x1, y1, z1 = leaf_func(t)
        if -3 * sqrt(3) < t < 0:
            x2, y2, z2 = leaf_middle(x1, y1, z1)
            f.write(str(x2) + ';' + str(y2) + ';' + str(z2) + '\n')
            coords_list.append([x2, y2, z2])

        f.write(str(x1) + ';' + str(y1) + ';' + str(z1) + '\n')
        coords_list.append([x1, y1, z1])

    f.close()

    x, y, z = numpy.array(list(i[0] for i in coords_list)), numpy.array(list(i[1] for i in coords_list)), numpy.array(
        list(i[2] for i in coords_list))
    ax.plot_trisurf(x, y, z, wflag=True, filename="leaf_grid.txt")

    # plot grid
    # plot_grid('leaf_grid.txt', ax)


def center_func(x, y):
    return 2/3 * sqrt(-(x - 0.25)**2 - y**2 + 5) + 21.2


def get_center(ax):
    # create grid
    f = open('center_points.txt', 'w')

    x_start, x_stop, x_step = -4.75, 5.25, poly_step
    x_list = numpy.linspace(x_start, x_stop, ceil((x_stop - x_start) / x_step))
    y_start, y_stop, y_step = -5, 5, poly_step
    y_list = numpy.linspace(y_start, y_stop, ceil((y_stop - y_start) / y_step))

    coords_list = []

    for x in x_list:
        for y in y_list:
            if -(x - 0.25)**2 - y**2 + 5 > 0:
                z = center_func(x, y)
                f.write(str(x) + ';' + str(y) + ';' + str(z) + '\n')

                coords_list.append([x, y, z])

    f.close()

    x, y, z = numpy.array(list(i[0] for i in coords_list)), numpy.array(list(i[1] for i in coords_list)), numpy.array(
        list(i[2] for i in coords_list))
    ax.plot_trisurf(x, y, z, wflag=True, filename="center_grid.txt")

    # plot grid
    # plot_grid('center_grid.txt', ax)


def surface_func(x, y):
    return 0


def get_surface(ax):
    # create grid
    f = open('surface_points.txt', 'w')

    x_start, x_stop, x_step = -15, 15, 0.75
    x_list = numpy.linspace(x_start, x_stop, ceil((x_stop - x_start) / x_step))
    y_start, y_stop, y_step = -15, 15, 0.75
    y_list = numpy.linspace(y_start, y_stop, ceil((y_stop - y_start) / y_step))

    coords_list = []

    for x in x_list:
        for y in y_list:
            z = surface_func(x, y)
            f.write(str(x) + ';' + str(y) + ';' + str(z) + '\n')

            coords_list.append([x, y, z])

    f.close()

    x, y, z = numpy.array(list(i[0] for i in coords_list)), numpy.array(list(i[1] for i in coords_list)), numpy.array(
        list(i[2] for i in coords_list))
    ax.plot_trisurf(x, y, z, wflag=True, filename="surface_grid.txt")

    # plot grid
    # plot_grid('surface_grid.txt', ax)


if __name__ == '__main__':
    fig = plt.figure()
    axis = fig.add_subplot(projection='3d')

    get_receptacle(axis)
    get_stem(axis)
    get_petal(axis)
    get_leaf(axis)
    get_center(axis)
    get_surface(axis)

    # plt.show()
