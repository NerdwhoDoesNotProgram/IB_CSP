from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html', title='Mount Timpanogos')

@app.route('/explore')
def explore():
    return render_template('explore.html')

@app.route('/secret')
def secret():
    return render_template('secret.html')

app.run(debug=True)