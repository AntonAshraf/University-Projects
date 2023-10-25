from tkinter import *

def bisection(f, a, b, tolerance, max_iterations):

    steps_text = "\nBisection Steps of Iteration:\n\n"
    steps_text += "N\t Xu\t Xm\t Xl\t F(Xu)\t F(Xm)\t F(Xl)\t error\n\n"
    try:
        if f(a) * f(b) >= 0:
            error_msg = "The boundary values do not bracket the root.\n The function values at the boundary values are:\n f({}) = {} and f({}) = {}".format(
                a, f(a), b, f(b))
            return None, None, error_msg, steps_text
        old_mid_point = 0
        for n in range(1, max_iterations+1):
            mid_point = (a + b) / 2
            error = abs(mid_point - old_mid_point)
            if abs(f(mid_point)) < tolerance:
                steps_text += f"{n}\t {a:.3f}\t {mid_point:.3f}\t {b:.3f}\t {f(a):.3f}\t {f(mid_point):.3f}\t {f(b):.3f}\t {error:.3f}\n"
                return mid_point, abs(f(mid_point)), "Number of iterations: {}".format(n), steps_text
            elif f(a) * f(mid_point) < 0:
                b = mid_point
            else:
                a = mid_point
            steps_text += f"{n}\t {a:.3f}\t {mid_point:.3f}\t {b:.3f}\t {f(a):.3f}\t {f(mid_point):.3f}\t {f(b):.3f}\t {error:.3f}\n"
            old_mid_point = mid_point
    except Exception as e:
        error_msg = f"The method failed with the following error:\n{e}\n Try a different interval.\n The function values at the boundary values are:\n f({a}) = {f(a)} and f({b}) = {f(b)}"
        return None, None, error_msg, steps_text
    error_msg = "The method failed after {} iterations.".format(max_iterations)
    steps_text += "\n" + error_msg
    return mid_point, abs(f(mid_point)), error_msg, steps_text
