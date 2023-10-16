def secant(f, x0, x1, tolerance, max_iterations):
    for i in range(max_iterations):
        if abs(f(x1)) < tolerance:
            return x1, abs(f(x1)), "number of iterations: {}".format(i)
        try:
            denominator = float(f(x1) - f(x0))/(x1 - x0)
            x = x1 - float(f(x1))/denominator
        except ZeroDivisionError:
            error_msg = "Zero division error in secant method!"
            return None, None, error_msg
        x0, x1 = x1, x
    return x1, abs(f(x1)), "the method failed after {} iterations.".format(max_iterations)
