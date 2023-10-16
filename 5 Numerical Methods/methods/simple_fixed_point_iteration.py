def simple_fixed_point_iteration(f, x0, tolerance, max_iterations):
    for i in range(max_iterations):
        fx = f(x0)
        if abs(fx) < tolerance:
            return x0, abs(fx), "Number of iterations: {}".format(i)
        x0 = fx
    return x0, abs(f(x0)), "the method failed after {} iterations.".format(max_iterations)