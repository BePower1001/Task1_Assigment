import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
import joblib
import os

DATASET_PATH = r"C:\Users\adria\CLionProjects\Task1_Assigment\emails.csv"

def train_model_from_csv(csv_path):
    if not os.path.exists(csv_path):
        print(f"Dataset not found: {csv_path}")
        return

    df = pd.read_csv(csv_path)

    # Ensure required columns exist
    if "text" not in df.columns or "label" not in df.columns:
        print("CSV must contain 'text' and 'label' columns.")
        return

    X = df["text"]
    y = df["label"]

    vectorizer = TfidfVectorizer()
    X_vec = vectorizer.fit_transform(X)

    model = LogisticRegression()
    model.fit(X_vec, y)

    joblib.dump(model, "phishguard_model.pkl")
    joblib.dump(vectorizer, "phishguard_vectorizer.pkl")
    print("✅ Model trained and saved successfully.")

def detect_phishing(email_text):
    vectorizer = joblib.load("phishguard_vectorizer.pkl")
    model = joblib.load("phishguard_model.pkl")
    X_test = vectorizer.transform([email_text])
    pred = model.predict(X_test)[0]
    confidence = model.predict_proba(X_test)[0][pred]
    return ("Phishing", confidence) if pred == 1 else ("Safe", confidence)

if __name__ == "__main__":
    train_model_from_csv(DATASET_PATH)

    print("\n🛡️  PhishGuard Email Scanner")
    while True:
        email = input("Enter email text (or 'exit' to quit): ")
        if email.lower() == "exit":
            break
        result, confidence = detect_phishing(email)
        print(f"Result: {result} (Confidence: {confidence:.2f})\n")