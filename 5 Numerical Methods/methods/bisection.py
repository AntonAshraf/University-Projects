def bisection(f, a, b, tolerance, max_iterations):
    if f(a) * f(b) >= 0:
        error_msg = "The boundary values do not bracket the root.\n The function values at the boundary values are:\n f({}) = {} and f({}) = {}".format(a, f(a), b, f(b))
        print(f"{error_msg} The boundary values are f({a}) = {f(a)} and f({b}) = {f(b)}")
        return None, None, error_msg
    for n in range(1, max_iterations+1):
        mid_point = (a + b) / 2
        if abs(f(mid_point)) < tolerance:
            return mid_point, abs(f(mid_point)), "Number of iterations: {}".format(n)
        elif f(a) * f(mid_point) < 0:
            b = mid_point
        else:
            a = mid_point
    return mid_point, abs(f(mid_point)), "the method failed after {} iterations.".format(max_iterations)
