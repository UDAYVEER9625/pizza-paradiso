document.getElementById("checkout-form").addEventListener("submit", placeOrder);

function placeOrder(event) {
    event.preventDefault();
    let orderData = {
        customerID: localStorage.getItem("userID"),
        cart: JSON.parse(localStorage.getItem("cart")),
        totalAmount: document.getElementById("cart-total").innerText.replace("Total: ₹", "")
    };

    fetch("/api/orders", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(orderData)
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            localStorage.removeItem("cart");
            window.location.href = "payment.html?orderID=" + data.orderID;
        } else {
            alert("Error placing order!");
        }
    });
}
