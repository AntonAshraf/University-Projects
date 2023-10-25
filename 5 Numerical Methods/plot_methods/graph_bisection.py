import matplotlib.pyplot as plt
import numpy as np

def plot_bisection_method(f, a, b, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(a, b, 100)
    y = f(x)

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))  # Adjust the figsize parameter to set the width and height

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Define a color map for the points
    cmap = plt.get_cmap('viridis')

    # Perform the Bisection method iterations
    while iteration < max_iterations:
        # Calculate the midpoint
        c = (a + b) / 2

        # Print the iteration details
        print(f"Iteration {iteration+1}: a = {a:.4f}, b = {b:.4f}, c = {c:.4f}, f(a) = {f(a):.4f}, f(b) = {f(b):.4f}, f(c) = {f(c):.4f}")

        # Plot the midpoint with a different color for each iteration
        color = cmap(iteration / max_iterations)
        ax.plot(c, f(c), 'o', color=color, label=f'Iteration {iteration+1}')

        # Check if the root is found
        if np.isclose(f(c), 0) or abs(b - a) < tolerance:
            break

        # Update the interval based on the sign of f(c)
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c

        # Increment the iteration counter
        iteration += 1

    # Add labels and legend to the plot
    ax.set_xlabel('x')
    ax.set_ylabel('f(x)')
    ax.legend()

    # Add a title and annotation for the root
    ax.set_title('Bisection Method')
    ax.annotate(f'Root: x = {c:.4f}', xy=(c, f(c)), xytext=(c, f(c) + 0.5),
                arrowprops=dict(facecolor='black', arrowstyle='->'))

    # Show the x and y axes
    ax.axhline(0, color='black', linewidth=0.5)
    ax.axvline(0, color='black', linewidth=0.5)
    
    # Show the plot
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
