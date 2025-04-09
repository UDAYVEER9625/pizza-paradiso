document.addEventListener("DOMContentLoaded", () => {
    loadPizzaMenu();
});

function loadPizzaMenu() {
    fetch("/api/pizzas")
        .then(response => response.json())
        .then(data => {
            const menuContainer = document.getElementById("menu-list");
            menuContainer.innerHTML = "";
            data.forEach(pizza => {
                menuContainer.innerHTML += `
                    <div class="pizza-card">
                        <img src="${pizza.image}" alt="${pizza.name}">
                        <h3>${pizza.name}</h3>
                        <p>${pizza.description}</p>
                        <span>₹${pizza.price}</span>
                        <button onclick="addToCart(${pizza.pizzaID})">Add to Cart</button>
                    </div>`;
            });
        });
}
