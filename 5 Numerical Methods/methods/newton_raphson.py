def newton_raphson(f, x0, tolerance, max_iterations):
    for i in range(max_iterations):
        fx = f(x0)
        if abs(fx) < tolerance:
            return x0, abs(fx), "Number of iterations: {}".format(i)
        dfx = (f(x0 + tolerance) - fx) / tolerance
        if dfx == 0:
            error_msg = "The derivative is zero."
            return None, None, error_msg
        x0 = x0 - fx / dfx
    return x0, abs(f(x0)), "the method failed after {} iterations.".format(max_iterations)
