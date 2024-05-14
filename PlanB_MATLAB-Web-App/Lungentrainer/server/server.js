const express = require('express');
const app = express();
const port = process.env.PORT || 3000; // Render assigns a port via process.env.PORT

// Serve your MATLAB web app's static files
app.use(express.static('./Lungentrainer_2'));

// If you have an index.html file, you can set up a route like this:
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/Lungentrainer_2/PackagingLog.html');
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});