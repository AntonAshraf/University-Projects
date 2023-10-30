import matplotlib.pyplot as plt
import numpy as np
import time

def plot_false_position_method(f, a, b, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(a - 10, b + 10, 100)
    y = np.array([f(xi) for xi in x])


    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Perform the False Position method iterations
    while iteration < max_iterations:
        # Calculate the function values at the endpoints
        fa = f(a)
        fb = f(b)

        # Calculate the new estimate
        x1 = (a * fb - b * fa) / (fb - fa)

        # Clear the current plot
        ax.clear()

        # Plot the function
        ax.plot(x, y, label='F(x)')

        # Plot the estimate with a different color for each iteration
        color = plt.cm.viridis(iteration / max_iterations)
        ax.plot(x1, f(x1), 'o', color=color, label=f'Iteration {iteration}')

        # Plot vertical lines for a and b
        ax.axvline(a, color='red', linestyle='--', label='a')
        ax.axvline(b, color='blue', linestyle='--', label='b')

        # Add labels and legend to the plot
        ax.set_xlabel('x')
        ax.set_ylabel('f(x)')
        ax.legend()

        # Add a title and annotation for the root
        ax.set_title('False Position Method')
        ax.annotate(f'Root: x = {x1:.4f}', xy=(x1, f(x1)), xytext=(x1, f(x1) + 0.5),
                    arrowprops=dict(facecolor='black', arrowstyle='->'))

        # Show the x and y axes
        ax.axhline(0, color='black', linewidth=0.5)
        ax.axvline(0, color='black', linewidth=0.5)

        # Draw the plot
        plt.draw()
        plt.pause(1)  # Delay for 1 second

        # Check if the root is found
        if abs(x1 - a) < tolerance:
            break

        # Update the interval based on the sign of f(x1)
        if f(x1) * fa < 0:
            b = x1
        else:
            a = x1

        # Increment the iteration counter
        iteration += 1

    # Show the final plot
    plt.show()
    
    
if __name__ == '__main__':
    # Define the function
    def f(x):
        return x**3 - 6*x**2 + 11*x - 6.1

    # Set the initial guesses
    a = 0.0
    b = 1.0

    # Set the maximum number of iterations
    max_iterations = 10

    # Set the tolerance
    tolerance = 1e-4

    # Perform the False Position method iterations
    plot_false_position_method(f, a, b, max_iterations, tolerance)