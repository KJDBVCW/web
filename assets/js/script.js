function openModal(modalNumber) {
    var modal = document.getElementById("myModal" + modalNumber);
  
    // Display the modal
    modal.style.display = "block";
  }
  
  function closeModal(modalNumber) {
    var modal = document.getElementById("myModal" + modalNumber);
    modal.style.display = "none";
  }
  
  window.addEventListener("click", function(event) {
    // Close the modal if clicked outside the modal content
    if (event.target.classList.contains("modal")) {
      closeModal();
    }
  });
  