import matplotlib.pyplot as plt
import numpy as np
import time

def plot_newton_raphson_method(f, x0, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(x0 - 10, x0 + 10, 100)
    y = np.array([f(xi) for xi in x])


    # make lambda function for f_prime
    f_prime = lambda x: (f(x + tolerance) - f(x)) / tolerance

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Perform the Newton-Raphson method iterations
    while iteration < max_iterations:
        # Calculate the function value and derivative at the current estimate
        fx = f(x0)
        fpx = f_prime(x0)

        # Calculate the new estimate
        x1 = x0 - fx / fpx

        # Clear the current plot
        ax.clear()

        # Plot the function
        ax.plot(x, y, label='F(x)')

        # Plot the estimate with a different color for each iteration
        color = plt.cm.viridis(iteration / max_iterations)
        ax.plot(x1, f(x1), 'o', color=color, label=f'Iteration {iteration}')

        # Plot vertical line for the estimated root
        ax.axvline(x1, color='red', linestyle='--', label='Estimated Root')

        # Add labels and legend to the plot
        ax.set_xlabel('x')
        ax.set_ylabel('f(x)')
        ax.legend()

        # Add a title and annotation for the root
        ax.set_title('Newton-Raphson Method')
        ax.annotate(f'Root: x = {x1:.4f}', xy=(x1, f(x1)), xytext=(x1, f(x1) + 0.5),
                    arrowprops=dict(facecolor='black', arrowstyle='->'))

        # Show the x and y axes
        ax.axhline(0, color='black', linewidth=0.5)
        ax.axvline(0, color='black', linewidth=0.5)

        # Draw the plot
        plt.draw()
        plt.pause(1)  # Delay for 1 second

        # Check if the root is found
        if abs(x1 - x0) < tolerance:
            break

        # Update the estimate
        x0 = x1

        # Increment the iteration counter
        iteration += 1

    # Show the final plot
    plt.show()

if __name__ == '__main__':
    # Define the function
    f = lambda x: x**3 - 2*x**2 - 5
    f_prime = lambda x: 3*x**2 - 4*x

    # Define the initial guess
    x0 = 3

    # Set the maximum number of iterations and tolerance
    max_iterations = 10
    tolerance = 1e-4

    # Plot the function and iterations
    plot_newton_raphson_method(f, f_prime, x0, max_iterations, tolerance)