def simple_fixed_point_iteration(f, x0, tolerance, max_iterations):
    
    steps_text = "\nSimple Fixed-Point Iteration Steps of Iteration:\n\n"
    steps_text += "N\t Xn\t F(Xn)\n\n"
    
    for i in range(max_iterations):
        fx = f(x0)
        if abs(fx) < tolerance:
            steps_text += f"{i+1}\t {x0:.3f}\t {abs(fx):.3f}\n"
            return x0, abs(fx), "Number of iterations: {}".format(i), steps_text
        x0 = fx
        steps_text += f"{i+1}\t {x0:.3f}\t {abs(f(x0)):.3f}\n"
    
    error_msg = "The method failed after {} iterations.".format(max_iterations)
    steps_text += error_msg
    return x0, abs(f(x0)), error_msg, steps_text