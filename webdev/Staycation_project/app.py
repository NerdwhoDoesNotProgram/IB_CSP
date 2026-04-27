from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html', title='Mount Timpanogos')

@app.route('/explore')
def explore():
    return "<h1>Explore Page Coming Soon</h1>"

app.run(debug=True)