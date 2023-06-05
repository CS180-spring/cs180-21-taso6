var currentPage = 1;
var totalPages; // Total number of pages
var csvdata = '';

function buttonClickedPrev() {
    if(currentPage == 1){
        alert('No previous page');
    }
    else {
        var NextPage = false;
        updatePageNumbers(NextPage);
    }
    // });
}
function buttonClickedNext() {
    if(currentPage >= totalPages) {
        alert('No more pages');
    }
    else {
        var NextPage = true;
        updatePageNumbers(NextPage);
    }
}

function updatePageNumbers(NextPage) {
    if(NextPage == false &&
        currentPage > 1) { //prev
        currentPage--;
    }
    else if(NextPage == true &&
        currentPage < totalPages){
        currentPage++;
    }
    else{
        currentPage = totalPages;
    }
    readCSVFile(currentPage);
}

function loadPage(csvdata) {
    // Split by line break to gets rows Array
    var rowData = csvdata.split('\n');
    totalPages = rowData.length / 10;
    document.getElementById('pageNumberText').innerHTML = 'Page '+currentPage+' of '+parseInt(totalPages);

    // <table > <tbody>
    var tbodyEl = document.getElementById('tblcsvdata').getElementsByTagName('tbody')[0];
    tbodyEl.innerHTML = "";


    // Loop on the row Array (change row=0 if you also want to read 1st row)
    for (var row = currentPage; row < currentPage+10; row++) {

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

}

function readCSVFile(currentPage){
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
            csvdata = event.target.result;
            loadPage(csvdata);
        };

    }else{
        alert("Please select a file.");
    }

}
