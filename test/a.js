"use strict";
exports.__esModule = true;
var mongoose_1 = require("mongoose");
var TranscriptSchema = new mongoose_1.Schema({
    Name: { type: String, required: true },
    EmailId: { type: String },
    PostalAddress: { type: String },
    ContactNo: { type: Number, required: true },
    FeeRefId: { type: String, required: true },
    Purpose: { type: String, required: true },
    NoOfCopies: { type: Number, required: true },
    Document: { type: String, required: true },
    StudentId: { type: Number, required: true }
});
var Transcript;
try {
    Transcript = mongoose_1.model('Transcript');
}
catch (_a) {
    Transcript = mongoose_1.model('Transcript', TranscriptSchema);
}
exports["default"] = Transcript;
mongoose_1.connect('mongodb://localhost:27017/cr');
var a = new Transcript({ NoOfCopies: 12, Name: "Cena", FeeRefId: "CSPC22", PostalAddress: "Happu", ContactNo: 9566098334, EmailId: "none", Document: "/temp", Purpose: "ko", StudentId: 106120043 });
a.save();
