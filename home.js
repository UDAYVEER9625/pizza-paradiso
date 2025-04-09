document.addEventListener("DOMContentLoaded", () => {
    fetchFeaturedPizzas();
});

function fetchFeaturedPizzas() {
    fetch("/api/pizzas")
        .then(response => response.json())
        .then(data => {
            const pizzaContainer = document.getElementById("featured-pizzas");
            pizzaContainer.innerHTML = "";
            data.forEach(pizza => {
                pizzaContainer.innerHTML += `
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

function addToCart(pizzaID) {
    let cart = JSON.parse(localStorage.getItem("cart")) || [];
    cart.push(pizzaID);
    localStorage.setItem("cart", JSON.stringify(cart));
    alert("Pizza added to cart!");
}
