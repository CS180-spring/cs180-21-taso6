var currentPage = 1;
var totalPages = 10; // Total number of pages

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
              for (var row = 1; row < 11; row++) {
                
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
    updatePageNumbers();
    loadPage(currentPage);
    alert("working")
