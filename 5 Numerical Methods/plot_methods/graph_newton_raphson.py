import matplotlib.pyplot as plt
import numpy as np

def plot_newton_raphson_method(f, f_prime, x0, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(x0 - 10, x0 + 10, 100)
    y = f(x)

    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6)) # Adjust the figsize parameter to set the width and height

    # Plot the function
    ax.plot(x, y, label='f(x)')

    # Initialize the iteration counter
    iteration = 0

    # Define a color map for the points
    cmap = plt.get_cmap('viridis')

    # Perform the Newton-Raphson method iterations
    while iteration < max_iterations:
        # Calculate the new estimate
        x1 = x0 - f(x0) / f_prime(x0)

        # Print the iteration details
        print(f"Iteration {iteration+1}: x0 = {x0:.4f}, x1 = {x1:.4f}, f(x0) = {f(x0):.4f}, f'(x0) = {f_prime(x0):.4f}")

        # Plot the estimate with a different color for each iteration
        color = cmap(iteration / max_iterations)
        ax.plot(x1, f(x1), 'o', color=color, label=f'Iteration {iteration+1}')

        # Check if the root is found
        if np.isclose(f(x1), 0) or abs(x1 - x0) < tolerance:
            break

        # Update the estimate
        x0 = x1

        # Increment the iteration counter
        iteration += 1

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

    # Show the plot
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