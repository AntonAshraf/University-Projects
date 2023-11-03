import matplotlib.pyplot as plt
import numpy as np
import matplotlib.backends.backend_tkagg
plt.switch_backend("TkAgg")

def plot_bisection_method(f, a, b, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(a - 10, b + 10, 100)
    # y = f(x)
    y = np.array([f(xi) for xi in x])

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Perform the Bisection method iterations
    while iteration < max_iterations:
        # Calculate the midpoint
        c = (a + b) / 2

        # Clear the current plot
        ax.clear()

        # Plot the function
        ax.plot(x, y, label='F(x)')

        # Plot the midpoint with a different color for each iteration
        color = plt.cm.viridis(iteration / max_iterations)
        ax.plot(c, f(c), 'o', color=color, label=f'Iteration {iteration+1}')

        # Plot vertical lines for a and b
        ax.axvline(a, color='red', linestyle='--', label='a')
        ax.axvline(b, color='blue', linestyle='--', label='b')

        # Add labels and legend to the plot
        ax.set_xlabel('x')
        ax.set_ylabel('F(x)')
        ax.legend()

        # Add a title and annotation for the root
        ax.set_title('Bisection Method')
        ax.annotate(f'Root: x = {c:.4f}', xy=(c, f(c)), xytext=(c, f(c) + 0.5),
                    arrowprops=dict(facecolor='black', arrowstyle='->'))

        # Show the x and y axes
        ax.axhline(0, color='black', linewidth=0.5)
        ax.axvline(0, color='black', linewidth=0.5)

        # Draw the plot
        plt.draw()
        plt.pause(1)  # Delay for 1 second

        # Check if the root is found
        if np.abs(b - a) < tolerance:
            break

        # Update the interval based on the sign of f(c)
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c

        # Increment the iteration counter
        iteration += 1

    # Show the final plot
    plt.show()
    
    
if __name__ == '__main__':
    # Define the function
    def f(x):
        return x**3 - 2*x - 5

    # Define the interval
    a = 2
    b = 3

    # Set the maximum number of iterations and tolerance
    max_iterations = 10
    tolerance = 1e-4

    # Perform the Bisection method
    plot_bisection_method(f, a, b, max_iterations, tolerance)
