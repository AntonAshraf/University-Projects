# This file contains the implementation of the false position method.
def false_position(f, a, b, tolerance, max_iterations):
    if f(a) * f(b) >= 0:
        error_msg = "The boundary values do not bracket the root.\n The function values at the boundary values are:\n f({}) = {} and f({}) = {}".format(a, f(a), b, f(b))
        return None, None, error_msg
    x = b - (b - a) * f(b) / (f(b) - f(a))
    for n in range(1, max_iterations+1):
        if f(a) * f(x) < 0:
            b = x
        else:
            a = x
        x_prev = x
        x = b - (b - a) * f(b) / (f(b) - f(a))
        if abs(x - x_prev) < tolerance:
            return x, abs(x - x_prev), "Number of iterations: {}".format(n)
    return x, abs(x - x_prev), "the method failed after {} iterations.".format(max_iterations)

