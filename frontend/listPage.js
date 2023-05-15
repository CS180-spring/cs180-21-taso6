var currentPage = 1;
var totalPages = 10; // Total number of pages

// var fileInput = document.getElementById('fileInput');
// var loadButton = document.getElementById('loadButton');

// loadButton.addEventListener('click', function() {
//   var file = fileInput.files[0];
//   var reader = new FileReader();

//   reader.onload = function(e) {
//     var csvData = e.target.result;
//     var rows = csvData.split('\n');

//     // Rest of the code to process the CSV data
//     for (var i = 0; i < rows.length; i++) {
//       var columns = rows[i].split(',');
//       // Process each column of the CSV data
//       // Example: Log each column to the console
//       console.log(columns);
//     }
//   };

//   var csvFilePath = '../eBird_1k_cleaned.csv'; // Replace with your CSV file path
// //   alert(csvFilePath)
//   var url = new URL(csvFilePath, window.location.href).href;
//   fetch(url)
//     .then(response => response.text())
//     .then(csvData => {
//       reader.readAsText(file);
//     })
//     .catch(error => {
//       console.error('Error:', error);
//     });
// });


function readCSVFile(page){
    var files = document.querySelector('#file').files;
    if(files.length > 0 ){

         // Selected file
         var file = files[0];

         // FileReader Object
         var reader = new FileReader();

         // Read file as string 
         reader.readAsText(file);

         // Load event
         reader.onload = function(event) {
              // Read file data
              var csvdata = event.target.result;

              // Split by line break to gets rows Array
              var rowData = csvdata.split('\n');

              // <table > <tbody>
              var tbodyEl = document.getElementById('tblcsvdata').getElementsByTagName('tbody')[0];
              tbodyEl.innerHTML = "";

              
              // Loop on the row Array (change row=0 if you also want to read 1st row)
              for (var row = 1; row < rowData.length; row++) {
                
                    // Insert a row at the end of table
                    var newRow = tbodyEl.insertRow();

                    // Split by comma (,) to get column Array
                    rowColData = rowData[row].split(',');

                    // Loop on the row column Array
                    for (var col = 0; col < rowColData.length; col++) {
                        if(col == 3 || col == 7 || col == 8 || col == 9){
                            // Insert a cell at the end of the row
                            var newCell = newRow.insertCell();
                            newCell.innerHTML = rowColData[col].replace(/"/g,'');
                        }
                    }

              }
         };

    }else{
         alert("Please select a file.");
    }

}


    function updatePageNumbers() {
      var pageNumbersContainer = document.getElementById('pageNumbers');
      pageNumbersContainer.innerHTML = '';

      for (var i = 1; i <= totalPages; i++) {
        var pageNumber = document.createElement('span');
        pageNumber.textContent = i;
        pageNumber.classList.add('page-number');

        if (i === currentPage) {
          pageNumber.classList.add('active');
        }

        pageNumber.addEventListener('click', function() {
          currentPage = parseInt(this.textContent);
          updatePageNumbers();
          // Call a function to load content for the new page
          loadPage(currentPage);
        });

        pageNumbersContainer.appendChild(pageNumber);
      }
    }

    // Function to load content for a specific page
    function loadPage(pageNumber) {
      // Implement your logic to load content for the given page
      console.log('Loading page', pageNumber);
    }

    // Initial setup
    // updatePageNumbers();
    // loadPage(currentPage);
    // alert("working")

    // var button = document.getElementsByClassName('pageButton');

    // // Add event listener to the button
    // button.addEventListener('click', function() {
    // // Code to be executed when the button is clicked
    //     alert('Button clicked!');
    // });
